package testcases.testset2.s02;
import testcasesupport.*;
import java.util.HashMap;

import javax.servlet.http.*;

public class testset2_74b
{
    public void foo_barSink(HashMap<Integer,String> dataHashMap , HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data = dataHashMap.get(2);

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }

    
    public void cwe_fooSink(HashMap<Integer,String> dataHashMap , HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String data = dataHashMap.get(2);

        if (data != null)
        {
            
            response.getWriter().println("<br>foo_bar(): data = " + data);
        }

    }
}
