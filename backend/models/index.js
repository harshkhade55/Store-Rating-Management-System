const { Sequelize, DataTypes } = require('sequelize');
const sequelize = new Sequelize(process.env.DB_NAME, process.env.DB_USER, process.env.DB_PASSWORD, {
  host: process.env.DB_HOST,
  dialect: process.env.DB_DIALECT || 'postgres',
  logging: false
});

const User = require('./user')(sequelize, DataTypes);
const Store = require('./store')(sequelize, DataTypes);
const Rating = require('./rating')(sequelize, DataTypes);

// Relations
User.hasMany(Rating, { foreignKey: 'userId' });
Rating.belongsTo(User, { foreignKey: 'userId' });

Store.hasMany(Rating, { foreignKey: 'storeId' });
Rating.belongsTo(Store, { foreignKey: 'storeId' });

// If a user is Store Owner, link:
User.hasMany(Store, { foreignKey: 'ownerId' });
Store.belongsTo(User, { foreignKey: 'ownerId' });

module.exports = { sequelize, User, Store, Rating };
