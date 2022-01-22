#include<bits/stdc++.h>

using namespace std;


int main()
{
   
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int t;
	cin>>t;
	
	while (t--)
	{
		int n,q;
		cin>>n;
		
		map<string,pair<string,vector<string>> > mp; 
		for (int i=0;i<n;++i)
		{
		   string s1,s2;
		   cin>>s1>>s2;
		   transform(s1.begin(),s1.end(),s1.begin(),::tolower);
		   transform(s2.begin(),s2.end(),s2.begin(),::tolower);
		   
		   if (!mp.count(s1) && !mp.count(s2))
           {
           	 vector<string> temp;
           	 mp[s1]=make_pair(s1,temp);
           	 mp[s2]=make_pair(s1,temp);
           	 
           	 mp[s1].second.push_back(s2);
           	 
		   }	
		   else if (mp.count(s1) && !mp.count(s2))
		   {
		   	 vector<string> temp;
		   	 
		   	 string parent=mp[s1].first;
		   	 
		   	 mp[s2]=make_pair(parent,temp);
		   	 
		   	 mp[parent].second.push_back(s2);
		   	 
	       }
	       else if(!mp.count(s1) && mp.count(s2))
	       {
	       	 vector<string> temp;
	       	 
	       	 string parent=mp[s2].first;
	       	 
	       	 mp[s1]=make_pair(parent,temp);
	       	 
	       	 mp[parent].second.push_back(s1);
		   }
		   else
		   {
		   	  string f_parent=mp[s1].first;
		   	  string s_parent=mp[s2].first;

			  if (f_parent==s_parent)
			  continue;	 
		   	  
		   	  mp[s_parent].first=f_parent;
		   	  
		   	  for (auto itr:mp[s_parent].second)
		   	  {
		   	      mp[itr].first=f_parent;
		   	  }
		   	  
		   	  
		   }
		   
		}
		
        

		cin>>q;
		
		while (q--)
		{
			string s1,s2;
			cin>>s1>>s2;
			
		    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
		    transform(s2.begin(),s2.end(),s2.begin(),::tolower);
			
			if (s1==s2)
			{
			    cout<<"synonym"<<endl;
			    continue;
			}
			
			if (mp.count(s1) && mp.count(s2) && mp[s1].first==mp[s2].first)
			cout<<"synonym"<<endl;
			else
			cout<<"different"<<endl;
			
			
			
		}
		
		
	}
	
	
return 0; 	
}

