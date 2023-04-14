package com.gel.dao.Impl;


import com.gel.dao.UserDao;
import com.gel.po.User;
import com.gel.utils.jdbcUtils;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Map;

public class UserDaoImpl implements UserDao {

    jdbcUtils jdbcUtils = com.gel.utils.jdbcUtils.getInstance();
    @Override
    public User getUserByUsername(User user) {

        ArrayList<Object> list = jdbcUtils.Query("select * from userlogin where username =?", new Object[]{user.getUsername()});
        User user1 = new User();
        Map map = (Map) list.get(0);
        user.setId((Integer) map.get("id")); ;
        user.setUsername((String) map.get("username"));
        user.setPassword((String) map.get("password"));
        System.out.println( jdbcUtils.Query("select * from userlogin where username =?",new Object[]{user.getUsername()}));
        return user;
    }

    @Override
    public boolean insertUserByUsername(User user) {
        try {
            int flag = jdbcUtils.Updata("INSERT INTO userlogin (,username,password) VALUES (,?,?)", new Object[]{user.getUsername(), user.getPassword()});
            if(flag!=0){
                return true;
            }

        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
        return false;
    }

    @Override
    public boolean updateUser(User user) {
        try {
            int flag = jdbcUtils.Updata("UPDATE userlogin SET password =? where username = ?", new Object[]{ user.getPassword(),user.getUsername()});
            if(flag!=0){
                return true;
            }

        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
        return false;
    }

    @Override
    public boolean deleteUser(User user) {
        try {
            int flag = jdbcUtils.Updata("DELETE FROM userlogin where username=?", new Object[]{user.getUsername()});
            if(flag!=0){
                return true;
            }

        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
        return false;
    }
}
