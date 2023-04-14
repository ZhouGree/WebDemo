package com.gel.controller.base;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.Method;

@WebServlet("/baseServlet")
public class BaseServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        response.setCharacterEncoding("utf-8");

        try{
            //  获取请求标识
            String methodName = request.getParameter("method");
            Class<? extends BaseServlet> actionClass = this.getClass();
            Method method = actionClass.getMethod(methodName,HttpServletRequest.class,HttpServletResponse.class);
            method.invoke(this,request,response);
        } catch (Exception e) {
            e.getStackTrace();
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request,response);
    }
}
