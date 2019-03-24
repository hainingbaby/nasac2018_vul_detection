package testcases.testset3;

import testcasesupport.*;

public class testset3_1_15 extends AbstractTestCase
{
    public void foo_bar() throws Throwable
    {
        switch (7)
        {
        case 7:
            int[] intArray = new int[10];
            int i = 0;
            do
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
                i++;
            }
            while (i <= intArray.length);   
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
            int[] intArray = new int[10];
            int i = 0;
            do
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
                i++;
            }
            while (i < intArray.length);   
            break;
        }
    }

    
    private void good2() throws Throwable
    {
        switch (7)
        {
        case 7:
            int[] intArray = new int[10];
            int i = 0;
            do
            {
                IO.writeLine("intArray[" + i + "] = " + (intArray[i] = i));
                i++;
            }
            while (i < intArray.length);   
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
