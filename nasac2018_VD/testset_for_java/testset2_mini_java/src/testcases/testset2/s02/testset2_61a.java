package testcases.testset2.s02;
import testcasesupport.*;

import javax.servlet.http.*;

public class testset2_61a extends AbstractTestCaseServlet
{
    public void foo_bar(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data = (new testset2_61b()).foo_barSource(request, response);

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }

    public void good(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        cwe_foo(request, response);
    }

    
    private void cwe_foo(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data = (new testset2_61b()).cwe_fooSource(request, response);

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
