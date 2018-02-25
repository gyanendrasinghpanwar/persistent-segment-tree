#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll array[]={18,17,13,19,15,11,20};
ll tree[1<<18];

void build(ll node,ll a, ll b)
{   //if(a>b) return;
	if(a==b){
    tree[node]=array[a];
    //cout<<tree[node]<<endl;
    return;
	}
	build(2*node,a,(a+b)/2);
	build(2*node+1,1+(a+b)/2,b);
	
	tree[node]=min(tree[node*2],tree[node*2+1]);
}

void update(ll node,ll a,ll b, ll i, ll j,ll value)
{
	if(a>b || b<i || a>j)
	return;
	if(a==b){
	tree[node]=value;
	//cout<<node<<"  and "<<tree[node];
	return;
    }
	
	update(node*2,a,(a+b)/2,i,j,value);    //update left child;
	update(node*2+1,1+(a+b)/2,b,i,j,value);   //update right child;
	
	tree[node]=min(tree[node*2],tree[node*2+1]);
}

ll query(ll node, ll a, ll b, ll i, ll j)
{
	if(a>b || b<i || a>j)
	return -1;
	if(a>=i && b<=j)
	return tree[node];
	
	ll q1=query(node*2,a,(a+b)/2,i,j);    //query left child;
	ll q2=query(node*2+1,1+(a+b)/2,b,i,j);   //query right child;
	if(q1==-1) return q2;
	if(q2==-1) return q1; 
	ll ans=min(q1,q2);
	return ans;
}

int main()
{
    ll n=sizeof(array)/sizeof(array[0]);
	build(1,0,n-1);
	
	ll x,y,value;  
	cout<<"enter the value of x and y as range where u want to update the value"<<endl;
	cin>>x>>y;
	cout<<"enter the value u want to update"<<endl;
	cin>>value;
	update(1,0,n-1,x,y,value);  
	cout<<"enter the range of index where u wish to find min no. "<<endl;
	
	ll i,j;
	cin>>i>>j;
	cout<<query(1,0,n-1,i,j)<<endl;
}
