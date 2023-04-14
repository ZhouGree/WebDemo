package com.gel.service.Impl;

import com.gel.dao.Impl.UserDaoImpl;
import com.gel.dao.UserDao;
import com.gel.po.User;
import com.gel.service.UserService;

public class UserServiceImpl implements UserService {
    private UserDao userDao = new UserDaoImpl();
    @Override
    public User Existence(User loginuser){
        User userByUsername = userDao.getUserByUsername(loginuser);
        return userByUsername;
    }

    @Override
    public User login(User loginuser) {
        User userByUsername = this.Existence(loginuser);

        if(userByUsername.getPassword().equals(loginuser.getPassword())){
            return userByUsername;
        }
        return null;
    }

    @Override
    public User register(User user) {

        if(user==null||user.getUsername()==null||user.getPassword()==null){
            return null;
        }
        if(userDao.getUserByUsername(user)!=null){
            return null;
        }
        if(userDao.insertUserByUsername(user)==false){
            return null;
        }
        return user;
    }
    @Override
    public boolean reset(User user){
        User userByUsername = this.Existence(user);
        if(userByUsername!=null){
            if(userDao.updateUser(userByUsername)==true){
                return true;
            }

        }
        return false;
    }
}
