const { User, Store, Rating } = require('../models');
const { Op } = require('sequelize');

exports.createUser = async (req, res) => {
  try {
    const { name, email, address, password, role } = req.body;
    const user = await User.create({ name, email, address, passwordHash: password, role: role || 'user' });
    res.json({ message: 'User created', user: { id: user.id, name: user.name }});
  } catch (err) { res.status(400).json({ message: err.message }); }
};

exports.createStore = async (req, res) => {
  try {
    const { name, email, address, ownerId } = req.body;
    const store = await Store.create({ name, email, address, ownerId: ownerId || null });
    res.json({ message: 'Store created', store });
  } catch (err) { res.status(400).json({ message: err.message }); }
};

exports.dashboard = async (req, res) => {
  const totalUsers = await User.count();
  const totalStores = await Store.count();
  const totalRatings = await Rating.count();
  res.json({ totalUsers, totalStores, totalRatings });
};

exports.listUsers = async (req, res) => {
  const { q, role } = req.query;
  const where = {};
  if (role) where.role = role;
  if (q) where[Op.or] = [
    { name: { [Op.iLike]: `%${q}%` } },
    { email: { [Op.iLike]: `%${q}%` } },
    { address: { [Op.iLike]: `%${q}%` } }
  ];
  const users = await User.findAll({ where, attributes:['id','name','email','address','role']});
  res.json(users);
};

exports.listStores = async (req, res) => {
  const { q } = req.query;
  const where = {};
  if (q) where[Op.or] = [
    { name: { [Op.iLike]: `%${q}%` } },
    { email: { [Op.iLike]: `%${q}%` } },
    { address: { [Op.iLike]: `%${q}%` } }
  ];
  const stores = await Store.findAll({
    where,
    attributes:['id','name','email','address'],
    include: [{ model: Rating, attributes:['value'] }]
  });
  // compute overall rating
  const result = stores.map(s => {
    const values = s.Ratings.map(r=>r.value);
    const avg = values.length? (values.reduce((a,b)=>a+b,0)/values.length).toFixed(2) : null;
    return { id:s.id, name:s.name, email:s.email, address:s.address, rating: avg };
  });
  res.json(result);
};
