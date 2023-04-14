package com.gel.controller;

import com.gel.controller.base.BaseServlet;
import com.gel.po.User;
import com.gel.service.Impl.UserServiceImpl;
import com.gel.service.UserService;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/userServlet/*")
public class UserServlet extends BaseServlet {
    public User pack(HttpServletRequest request, HttpServletResponse response)  {
        String username = request.getParameter("username");
        String password = request.getParameter("password");

        User loginuser = new User();
        loginuser.setUsername(username);
        loginuser.setPassword(password);
        return loginuser;
    }

    private UserService userService = new UserServiceImpl();

    public User Existence(HttpServletRequest request, HttpServletResponse response){
        User loginuser = this.pack(request,response);
        User user  = userService.Existence(loginuser);
        return user;
    }

    protected void login(HttpServletRequest request, HttpServletResponse response) throws IOException {

        User loginuser = this.Existence(request, response);
        User user = userService.login(loginuser);
        if(user==null){
            response.getWriter().write("用户名不存在或密码错误");
        }
        else {
            response.getWriter().write("登陆成功");
        }
    }
    protected void register(HttpServletRequest request, HttpServletResponse response) throws IOException {
        User loginuser = this.Existence(request, response);
        User user = userService.register(loginuser);
        if(user==null){
            response.sendRedirect("register.html");

        }
        else {
            response .sendRedirect("index.html");
        }

    }
    protected  void ResetPassword(HttpServletRequest request, HttpServletResponse response) throws IOException {
        User user = this.Existence(request, response);
       if(userService.reset(user)==true){
           response.getWriter().write("请重新登录！");
           response .sendRedirect("index.html");
       }else {
           response.getWriter().write("重置密码失败！");
       }
    }

}
