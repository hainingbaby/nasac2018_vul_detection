package testcases.testset3;

import testcasesupport.*;

public class testset3_1_04 extends AbstractTestCase
{

    private static final boolean PRIVATE_STATIC_FINAL_TRUE = true;
    private static final boolean PRIVATE_STATIC_FINAL_FALSE = false;

    public void foo_bar() throws Throwable
    {
        if (PRIVATE_STATIC_FINAL_TRUE)
        {
            int[] intArray = new int[10];
            int i = 0;
            do
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
                i++;
            }
            while (i <= intArray.length);   
        }
    }

    
    private void good1() throws Throwable
    {
        if (PRIVATE_STATIC_FINAL_FALSE)
        {
            
            IO.writeLine("Benign, fixed string");
        }
        else
        {

            int[] intArray = new int[10];
            int i = 0;

            do
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
                i++;
            }
            while (i < intArray.length);   

        }
    }

    
    private void good2() throws Throwable
    {
        if (PRIVATE_STATIC_FINAL_TRUE)
        {
            int[] intArray = new int[10];
            int i = 0;
            do
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
                i++;
            }
            while (i < intArray.length);   
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
