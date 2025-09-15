const { User } = require('../models');
const jwt = require('jsonwebtoken');

function validatePasswordRules(pw) {
  if (!pw) return false;
  if (pw.length < 8 || pw.length > 16) return false;
  if (!/[A-Z]/.test(pw)) return false;
  if (!/[^A-Za-z0-9]/.test(pw)) return false;
  return true;
}

exports.signup = async (req, res) => {
  try {
    const { name, email, address, password } = req.body;
    if (!name || name.length < 20 || name.length > 60) return res.status(400).json({ message: 'Name length must be 20-60' });
    if (!validatePasswordRules(password)) return res.status(400).json({ message: 'Password must be 8-16, include uppercase and special char' });
    const user = await User.create({ name, email, address, passwordHash: password, role:'user' });
    return res.json({ message: 'User created' });
  } catch (err) {
    return res.status(400).json({ message: err.message });
  }
};

exports.login = async (req, res) => {
  try {
    const { email, password } = req.body;
    const user = await User.findOne({ where: { email }});
    if (!user) return res.status(400).json({ message: 'Invalid credentials' });
    const ok = await user.verifyPassword(password);
    if (!ok) return res.status(400).json({ message: 'Invalid credentials' });
    const token = jwt.sign({ id: user.id, role: user.role }, process.env.JWT_SECRET || 'secret', { expiresIn: '7d' });
    return res.json({ token, user: { id: user.id, name: user.name, email: user.email, role: user.role }});
  } catch (err) {
    return res.status(400).json({ message: err.message });
  }
};
