const jwt = require('jsonwebtoken');
const { User } = require('../models');

exports.authenticate = async (req, res, next) => {
  const auth = req.headers.authorization;
  if (!auth) return res.status(401).json({ message: 'Missing auth token' });
  const token = auth.split(' ')[1];
  try {
    const payload = jwt.verify(token, process.env.JWT_SECRET || 'secret');
    const user = await User.findByPk(payload.id);
    if (!user) return res.status(401).json({ message: 'Invalid token user' });
    req.user = user;
    next();
  } catch (err) {
    return res.status(401).json({ message: 'Invalid token' });
  }
};

exports.authorize = (roles=[]) => {
  return (req, res, next) => {
    if (!roles.length) return next();
    if (roles.includes(req.user.role)) return next();
    return res.status(403).json({ message: 'Forbidden' });
  };
};
