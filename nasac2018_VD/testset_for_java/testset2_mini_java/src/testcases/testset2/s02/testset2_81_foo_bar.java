package testcases.testset2.s02;
import testcasesupport.*;

import javax.servlet.http.*;

public class testset2_81_foo_bar extends testset2_81_base
{
    public void action(String data , HttpServletRequest request, HttpServletResponse response) throws Throwable
    {

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }
}
