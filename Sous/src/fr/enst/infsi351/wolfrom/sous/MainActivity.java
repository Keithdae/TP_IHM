package fr.enst.infsi351.wolfrom.sous;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

import android.net.Uri;
import android.os.Bundle;
import android.os.StrictMode;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        if (android.os.Build.VERSION.SDK_INT > 9) {
            StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
            StrictMode.setThreadPolicy(policy);
        }

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.activity_main, menu);
        return true;
    }
    
    
    public void convert(View sender)
    {
    	EditText euros = (EditText) findViewById(R.id.edit_euros);
    	EditText change = (EditText) findViewById(R.id.edit_change);
    	EditText dollars = (EditText) findViewById(R.id.edit_dollars);
    	String str_euros = euros.getText().toString();
    	String str_change = change.getText().toString();
    	if(!str_euros.equals("") && !str_change.equals(""))
    	{
	    	float e = Float.parseFloat(str_euros);
	    	float c = Float.parseFloat(str_change);
	    	dollars.setText(Float.toString(e*c));
	    	dollars.setVisibility(View.VISIBLE);
    	}
    }
    
    
    public void searchChangeRate(View sender)
    {
    	Intent intent = new Intent().setAction(Intent.ACTION_VIEW);
    	intent.setData(Uri.parse("https://finance.yahoo.com/currency-converter/#from=EUR;to=USD;amt=1"));
    	startActivity(intent);
    }
    
    public void getChangeRate(View sender)
    {
    	String h = "";
    	try {
			h = getHtml("https://openexchangerates.org/api/latest.json?app_id=40a48d570b694526ba64a4159b8970a1");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	int sub = h.indexOf("EUR", 0);
    	if(sub != -1)
    	{
    		String change = h.substring(sub+6, sub+14);
    		float true_change = 1/(Float.parseFloat(change));
        	EditText change_edit = (EditText) findViewById(R.id.edit_change);
        	change_edit.setText(Float.toString(true_change));
    	}
    }
    
    public static String getHtml(String url) throws IOException {
    	HttpClient client = new DefaultHttpClient();
    	HttpGet request = new HttpGet(url);
    	HttpResponse response = client.execute(request);

    	String html = "";
    	InputStream in = response.getEntity().getContent();
    	BufferedReader reader = new BufferedReader(new InputStreamReader(in));
    	StringBuilder str = new StringBuilder();
    	String line = null;
    	while((line = reader.readLine()) != null)
    	{
    	    str.append(line);
    	}
    	in.close();
    	html = str.toString();

        return html;
    }
}
