package testcases.testset4;

import testcasesupport.*;

public class testset4_1_15 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        switch (7)
        {
        case 7:
        {
            
            String myString = null;
            if (myString == null)
            {
                IO.writeLine(myString.length());
            }
        }
        break;
        default:
            
            IO.writeLine("Benign, fixed string");
            break;
        }
    }

    
    private void good1() throws Throwable
    {
        switch (8)
        {
        case 7:
            
            IO.writeLine("Benign, fixed string");
            break;
        default:
        {
            
            String myString = null;
            if (myString == null)
            {
                IO.writeLine("The string is null");
            }
        }
        break;
        }
    }

    
    private void good2() throws Throwable
    {
        switch (7)
        {
        case 7:
        {
            
            String myString = null;
            if (myString == null)
            {
                IO.writeLine("The string is null");
            }
        }
        break;
        default:
            
            IO.writeLine("Benign, fixed string");
            break;
        }
    }

    public void good() throws Throwable
    {
        good1();
        good2();
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
