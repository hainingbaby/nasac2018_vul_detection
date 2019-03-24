package testcases.testset2.s02;
import testcasesupport.*;

import javax.servlet.http.*;

public class testset2_22a extends AbstractTestCaseServlet
{
    

    public static boolean foo_barPublicStatic = false;

    public void foo_bar(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        foo_barPublicStatic = true;
        data = (new testset2_22b()).foo_barSource(request, response);

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }

    

    public static boolean cwe_foo1PublicStatic = false;
    public static boolean cwe_foo2PublicStatic = false;

    public void good(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        cwe_foo1(request, response);
        cwe_foo2(request, response);
    }

    
    private void cwe_foo1(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        cwe_foo1PublicStatic = false;
        data = (new testset2_22b()).cwe_foo1Source(request, response);

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }

    
    private void cwe_foo2(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data;

        cwe_foo2PublicStatic = true;
        data = (new testset2_22b()).cwe_foo2Source(request, response);

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }

}
