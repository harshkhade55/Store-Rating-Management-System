const express = require('express');
const router = express.Router();
const auth = require('../middleware/auth');
const controllers = require('../controllers');

router.post('/auth/signup', controllers.auth.signup);
router.post('/auth/login', controllers.auth.login);

// Admin routes
router.post('/admin/users', auth.authenticate, auth.authorize(['admin']), controllers.admin.createUser);
router.post('/admin/stores', auth.authenticate, auth.authorize(['admin']), controllers.admin.createStore);
router.get('/admin/dashboard', auth.authenticate, auth.authorize(['admin']), controllers.admin.dashboard);
router.get('/admin/users', auth.authenticate, auth.authorize(['admin']), controllers.admin.listUsers);
router.get('/admin/stores', auth.authenticate, auth.authorize(['admin']), controllers.admin.listStores);

// Store listing and rating for normal users
router.get('/stores', auth.authenticate, controllers.store.listStores);
router.get('/stores/:id/ratings', auth.authenticate, controllers.store.listRatingsForStore);
router.post('/stores/:id/rate', auth.authenticate, controllers.store.submitRating);

// Owner dashboard
router.get('/owner/dashboard', auth.authenticate, auth.authorize(['owner']), controllers.owner.dashboard);

module.exports = router;
