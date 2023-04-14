package com.zhouzhou.servlet;


import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/demo3")
public class ServletDemo02 extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException{
           int status = Integer.parseInt(request.getParameter("status"));

           response.setContentType("text/html");
           //设置状态码
           response.setStatus(status);
           //response.setHeader("content-type","text/html;charset=utf-8");
           //response.getWriter().write("<h1>"+status+"</h1>");
           PrintWriter out = response.getWriter();
           out.println("<html>");
           out.println("<head>");
           out.println("<title>Status Code Form</title>");
           out.println("</head>");
           out.println("<body>");
            switch (status){
                case 200:out.println("<h1>200 OK</h1>");break;
                case 301:out.println("<h1>301 Moved Permanently</h1>");break;
                case 302:out.println("<h1>302 Found or Temporary</h1>");break;
                case 304:out.println("<h1>304 Not Modified</h1>");break;
                case 400:out.println("<h1>400 Bad Request</h1>");break;
                case 401:out.println("<h1>401 Unauthorized</h1>");break;
                case 403:out.println("<h1>403 Forbidden</h1>");break;
                case 404:out.println("<h1>404 Not Found</h1>");break;
                case 405:out.println("<h1>405 Method Not Allow</h1>");break;
                case 500:out.println("<h1>500 Internal Server Error</h1>");break;
            }
            out.println("</body>");
            out.println("</html>");
            out.close();
    }


    @Override
    protected void  doPost(HttpServletRequest request,HttpServletResponse response)
        throws ServletException,IOException{
        doGet(request,response);
    }
   /* @Override
    protected void doPut(HttpServletRequest request,HttpServletResponse response) throws IOException {
        try {
            doGet(request,response);
        } catch (ServletException e) {
            e.printStackTrace();
        }
    }
    @Override
    protected void doDelete(HttpServletRequest request,HttpServletResponse response) throws IOException {

    }*/

}
