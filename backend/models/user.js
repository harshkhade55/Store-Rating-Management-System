const bcrypt = require('bcrypt');

module.exports = (sequelize, DataTypes) => {
  const User = sequelize.define('User', {
    name: { type: DataTypes.STRING, allowNull:false, validate: { len: [20,60] } },
    email: { type: DataTypes.STRING, allowNull:false, unique:true, validate: { isEmail:true } },
    address: { type: DataTypes.STRING(400), allowNull:true },
    passwordHash: { type: DataTypes.STRING, allowNull:false },
    role: { type: DataTypes.ENUM('admin','user','owner'), defaultValue: 'user' }
  }, {
    tableName: 'users'
  });

  User.prototype.verifyPassword = function(password) {
    return bcrypt.compare(password, this.passwordHash);
  };

  User.beforeCreate(async (user) => {
    const salt = await bcrypt.genSalt(10);
    user.passwordHash = await bcrypt.hash(user.passwordHash, salt);
  });

  User.beforeUpdate(async (user) => {
    if (user.changed('passwordHash')) {
      const salt = await bcrypt.genSalt(10);
      user.passwordHash = await bcrypt.hash(user.passwordHash, salt);
    }
  });

  return User;
};
