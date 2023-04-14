package com.gel.service;

import com.gel.po.User;

public interface UserService {
   User login(User user);
   User register(User user);
   User Existence(User user);
   boolean reset(User user);
}
