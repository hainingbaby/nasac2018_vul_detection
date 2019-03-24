package testcases.testset3;

import testcasesupport.*;

public class testset3_3_16 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        while(true)
        {
            int[] intArray = new int[10];
            int i = 0;
            
            while (i <= intArray.length)
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
                i++;
            }
            break;
        }
    }

    
    private void good1() throws Throwable
    {
        while(true)
        {
            int[] intArray = new int[10];
            int i = 0;
            
            while (i < intArray.length)
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
                i++;
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
