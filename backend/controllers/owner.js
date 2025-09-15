const { Store, Rating, User } = require('../models');
exports.dashboard = async (req, res) => {
  // find stores owned by this owner
  const stores = await Store.findAll({ where: { ownerId: req.user.id }, include: [{ model: Rating, include:[{model:User, attributes:['id','name','email']}] }]});
  const payload = stores.map(s => {
    const values = s.Ratings.map(r=>r.value);
    const avg = values.length? (values.reduce((a,b)=>a+b,0)/values.length).toFixed(2) : null;
    const users = s.Ratings.map(r => ({ id:r.User.id, name:r.User.name, email:r.User.email, rating: r.value }));
    return { id:s.id, name:s.name, averageRating: avg, raters: users };
  });
  res.json(payload);
};
