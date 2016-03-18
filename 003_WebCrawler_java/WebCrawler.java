import java.net.*;
import java.io.*;

public class WebCrawler {
	
	public static void main(String[] args) {
		try{
			String urlstr = "http://www.example.com";
			URL url = new URL(urlstr);
			BufferedReader bf;
			String line;
			String result="";

			bf = new BufferedReader(new InputStreamReader(url.openStream()));
			
			while((line=bf.readLine())!=null){
				result=result.concat(line);
				System.out.println(line);
			}
			
			bf.close();
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
}
