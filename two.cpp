void inOrder(Node* root,vector<int> &v)
{
    if(root==NULL)
     return;
   
    inOrder(root->left,v);
   
    v.push_back(root->data);
   
    inOrder(root->right,v);
}
void traverse(Node* root,map<vector<int>,int> &mp)
{
    if(root==NULL)
      return;
    
    vector<int> v;
    inOrder(root,v);
    sort(v.begin(),v.end());
    mp[v]++;
    
    traverse(root->left,mp);
    
    traverse(root->right,mp);
    
}
void printAllDups(Node* root)
{
    map<vector<int>,int> mp;
    traverse(root,mp);
    int flag=0;
    for(auto i:mp)
    {
         if(i.second>1)
         {
            vector<int> v=i.first;
            cout<<v[0]<<" ";
            flag=1;
         }
    }
    if(flag==0)
     cout<<"-1"<<" ";
}