package testcases.testset4;

import testcasesupport.*;

public class testset4_1_08 extends AbstractTestCase
{

    private boolean privateReturnsTrue()
    {
        return true;
    }

    private boolean privateReturnsFalse()
    {
        return false;
    }

    public void foo_bar() throws Throwable
    {
        if (privateReturnsTrue())
        {
            {
                
                String myString = null;
                if (myString == null)
                {
                    IO.writeLine(myString.length());
                }
            }
        }
    }

    
    private void good1() throws Throwable
    {
        if (privateReturnsFalse())
        {
            
            IO.writeLine("Benign, fixed string");
        }
        else
        {

            {
                
                String myString = null;

                if (myString == null)
                {
                    IO.writeLine("The string is null");
                }
            }

        }
    }

    
    private void good2() throws Throwable
    {
        if (privateReturnsTrue())
        {
            {
                
                String myString = null;
                if (myString == null)
                {
                    IO.writeLine("The string is null");
                }
            }
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
