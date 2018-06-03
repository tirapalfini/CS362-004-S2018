

import junit.framework.TestCase;
//import static org.assertj.core.api.Assertions.*;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   /* This section is currently commented out as I'm not sure it adds purpose to the
    * program at this time.  Will re-assess later 
    */
   /*public String CompareResults(String intent, boolean expected, boolean actual) {
   	System.out.println(intent);
   	if (expected == actual) {
   		return "Result is as expected";	
   	}
   	else {
   		return "Result not expected";
   	}
   }
  	public void testResultPairs() {
	 //Determine whether ResultPairs is working
	   System.out.println("Checking validity of ResultPairs:");
	   ResultPair testCorrect = new ResultPair("correct", true);
	   ResultPair testIncorrect = new ResultPair("incorrect", false);
	   System.out.println(CompareResults("Check if true returns true", true, testCorrect.valid));
	   System.out.println(CompareResults("Check if false returns false", false, testIncorrect.valid));

   }
   
   public void testUrlCheck() {
	   //Determine whether UrlCheck is working
	   System.out.println("Checking validity of UrlCheck:");
	   UrlCheck testTrue = new UrlCheck("Check that true is true", true, true);
	   UrlCheck testFalse = new UrlCheck("Check that false is false", false, false);
	   UrlCheck testNotEqual = new UrlCheck("Check that true is not false", true, false);
	   System.out.println(testTrue.UrlCompareResults());
	   System.out.println(testFalse.UrlCompareResults());
	   System.out.println(testNotEqual.UrlCompareResults());
	   
   }*/
   
   /* Function for adding an item to a string array
    * http://grails.asia/how-to-add-element-to-string-array-in-java 
    */
   public static String[] add(String[] original, String newUrl)
   {
       int currentSize = original.length;
       int newSize = currentSize + 1;
       String[] temp = new String[ newSize ];
       for (int i=0; i < currentSize; i++)
       {
           temp[i] = original [i];
       }
       temp[newSize- 1] = newUrl;
       return temp;   
   }
   
   /* Function to iterate through urls and determine whether the 
    * isValid function and urlValidator produces the expected outcome.
    * If the results are as expected, url is added to list of 
    * successful/passed tests. If not as expected, url is added to list
    * of failed tests
    */
   public static void processUrls(UrlCheck[] sampleUrls)
   {
	   String[] urlsPassed = {};
	   String[] urlsFailed = {};
	   
	   for (int index = 0; index < sampleUrls.length; index++)
	   {
		   if (sampleUrls[index].Comparison() == true)
			  urlsPassed = add(urlsPassed, sampleUrls[index].url);
		   else
			   urlsFailed = add(urlsFailed, sampleUrls[index].url);
	   };
	   System.out.println("Tests Passed:");
	   for (String element: urlsPassed)
	   {
		   System.out.println(element);
	   }
	   System.out.println("\nTests Failed:");
	   for (String element: urlsFailed)
	   {
		   System.out.println(element);
	   }
   }
   /* This function tests various urls */
   public void testManualTest()
   {

//You can use this function to implement your manual testing
	   System.out.println("Testing with Default Schemes");
	   UrlValidator validate = new UrlValidator();
	   
	   UrlCheck[] sampleUrls = {
			   new UrlCheck(validate, "http://www.google.com", true),
			   new UrlCheck(validate, "http://www.oregonstate.edu", true),
			   new UrlCheck(validate, "http://www.yahoo.com", true),
			   new UrlCheck(validate, "https:google.com", true)
			   
	   };
	   
	   processUrls(sampleUrls);
	   
	   /*UrlValidator validator = new UrlValidator();
	   System.out.println(validator.isValid("https:google.com"));
	   System.out.println(validator.isValid("ftp:google.com"));
	   System.out.println(validator.isValid("http:google.com"));
	   System.out.println(validator.isValid(":google.com"));
	   System.out.println(validator.isValid("HTTP:google.com"));
	   System.out.println(validator.isValid("https:.com"));
	   System.out.println(validator.isValid("http:GOOGLE.com"));
	   System.out.println(validator.isValid("http:g@@gle.com"));
	   System.out.println(validator.isValid("http:google.co"));
	   System.out.println(validator.isValid("http:google.coM^"));
	   
	   UrlValidator validA = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(validA.isValid("http:google.com"));*/
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }

   
   public static void main(String[] argv) {

	
   }

}


