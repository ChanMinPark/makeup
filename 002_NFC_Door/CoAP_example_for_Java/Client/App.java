package com.pcm.CoAPSample;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import org.eclipse.californium.core.CoapClient;
import org.eclipse.californium.core.CoapHandler;
import org.eclipse.californium.core.CoapObserveRelation;
import org.eclipse.californium.core.CoapResponse;
public class App 
{
    public static void main( String[] args )
    {
//    	System.out.println( "Hello! This is CoAP Sample Application." );
//        
//        CoapClient client = new CoapClient("coap://californium.eclipse.org:5683/obs");
//        
//        if(!client.ping()){
//        	System.out.println("Server is down. Terminate program.");
//        	return;
//        }
//        
//        System.out.println("Request Get mothod of CoAP.");
//        String content1 = client.get().getResponseText();
//        System.out.println("Response : " + content1);


//        CoapResponse resp = client.put("payload", MediaTypeRegistry.TEXT_PLAIN); // for response details
//        System.out.println( resp.isSuccess() );
//        System.out.println( resp.getOptions() );
        
        
    	CoapClient client = new CoapClient("coap://californium.eclipse.org:5683/obs");

//    	client.get(new CoapHandler() { // e.g., anonymous inner class
//
//    		public void onLoad(CoapResponse response) { // also error resp.
//    			System.out.println("Get Response");
//    			String content = response.getResponseText();
//    			System.out.println( content );
//    		}
//
//    		public void onError() { // I/O errors and timeouts
//    			System.err.println("Failed");
//    		}
//    	});
    	
    	CoapObserveRelation relation = client.observe(
    			new CoapHandler() {
    				public void onLoad(CoapResponse response) {
    					String content = response.getResponseText();
    					System.out.println("NOTIFICATION: " + content);
    				}

    				public void onError() {
    					System.err.println("OBSERVING FAILED (press enter to exit)");
    				}
    			});

    	// wait for user
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	try { br.readLine(); } catch (IOException e) { }
    }
}
