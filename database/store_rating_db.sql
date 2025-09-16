
-- Create Database
CREATE DATABASE store_rating_db;

-- Connect to the database (manual step in psql: \c store_rating_db)

-- Enable useful extensions
CREATE EXTENSION IF NOT EXISTS "uuid-ossp";
CREATE EXTENSION IF NOT EXISTS "pgcrypto";

-- Users Table
CREATE TABLE users (
    user_id UUID DEFAULT uuid_generate_v4() PRIMARY KEY,
    username VARCHAR(100) UNIQUE NOT NULL,
    email VARCHAR(150) UNIQUE NOT NULL,
    password TEXT NOT NULL,
    role VARCHAR(50) CHECK (role IN ('admin', 'owner', 'user')) DEFAULT 'user',
    created_at TIMESTAMP DEFAULT NOW()
);

-- Stores Table
CREATE TABLE stores (
    store_id UUID DEFAULT uuid_generate_v4() PRIMARY KEY,
    store_name VARCHAR(200) NOT NULL,
    location VARCHAR(255),
    owner_id UUID REFERENCES users(user_id) ON DELETE SET NULL,
    created_at TIMESTAMP DEFAULT NOW()
);

-- Ratings Table
CREATE TABLE ratings (
    rating_id UUID DEFAULT uuid_generate_v4() PRIMARY KEY,
    user_id UUID REFERENCES users(user_id) ON DELETE CASCADE,
    store_id UUID REFERENCES stores(store_id) ON DELETE CASCADE,
    rating INT CHECK (rating >= 1 AND rating <= 5),
    review TEXT,
    created_at TIMESTAMP DEFAULT NOW(),
    UNIQUE(user_id, store_id)
);
