package testcases.testset2.s02;
import testcasesupport.*;

import javax.servlet.http.*;

public class testset2_68b
{
    public void foo_barSink(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data = testset2_68a.data;

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }

    
    public void cwe_fooSink(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data = testset2_68a.data;

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }
}
