package fr.enst.infsi351.wolfrom.sous;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
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
    
}
