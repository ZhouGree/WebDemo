package com.gel.dao;

import com.gel.po.User;

public interface UserDao {

   User getUserByUsername(User user);
   boolean insertUserByUsername(User user);
   boolean updateUser(User user);
   boolean deleteUser(User user);
}
