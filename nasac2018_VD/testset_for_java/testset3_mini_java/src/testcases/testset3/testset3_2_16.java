package testcases.testset3;

import testcasesupport.*;

public class testset3_2_16 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        while(true)
        {
            int[] intArray = new int[10];
            
            for (int i = 0; i <= intArray.length; i++)
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
            }
            break;
        }
    }

    
    private void good1() throws Throwable
    {
        while(true)
        {
            int[] intArray = new int[10];
            
            for (int i = 0; i < intArray.length; i++)
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
            }
            break;
        }
    }

    public void good() throws Throwable
    {
        good1();
    }

    public static void main(String[] args) throws ClassNotFoundException,
           InstantiationException, IllegalAccessException
    {
        mainFromParent(args);
    }
}
