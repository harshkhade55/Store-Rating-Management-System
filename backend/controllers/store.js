const { Store, Rating, User } = require('../models');

exports.listStores = async (req, res) => {
  const stores = await Store.findAll({
    include: [{ model: Rating, attributes:['value','userId'] }]
  });
  const payload = stores.map(s => {
    const values = s.Ratings.map(r=>r.value);
    const avg = values.length? (values.reduce((a,b)=>a+b,0)/values.length).toFixed(2) : null;
    const myRatingObj = s.Ratings.find(r => r.userId === req.user.id);
    return { id:s.id, name:s.name, address:s.address, overallRating: avg, myRating: myRatingObj ? myRatingObj.value : null };
  });
  res.json(payload);
};

exports.listRatingsForStore = async (req, res) => {
  const ratings = await Rating.findAll({ where: { storeId: req.params.id }, include:[{model:User, attributes:['id','name','email']}]});
  res.json(ratings);
};

exports.submitRating = async (req, res) => {
  try {
    const val = parseInt(req.body.value,10);
    if (!val || val <1 || val>5) return res.status(400).json({ message: 'Rating must be 1-5' });
    const storeId = req.params.id;
    const [rating, created] = await Rating.findOrCreate({ where: { storeId, userId: req.user.id }, defaults: { value: val } });
    if (!created) {
      rating.value = val;
      await rating.save();
    }
    res.json({ message: 'Rating saved', rating });
  } catch (err) { res.status(400).json({ message: err.message }); }
};
