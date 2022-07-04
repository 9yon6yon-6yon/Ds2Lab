#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long int source,destination,N,M,T1,T2,T3,i,j; //variable initializing
    cin>>source>>destination;//input taking
    cin>>N>>M;//input taking N junction M roads
    long long int t_int[N];
    //time interval input taking
    for(i=0; i<N; i++)
        cin>>t_int[i];

    t_int[destination-1]=0;

    vector<vector<pair<long long int,long long int> > > adj(N);
    for(i=0; i<M; i++)
    {
        cin>>T1>>T2>>T3;
        adj[T1-1].push_back({T2-1,T3});
        adj[T2-1].push_back({T1-1,T3});
    }
     //Applying dijkstra algorithm
    vector<long long int> dist(N,-1);
    dist[source-1]=0;
    set<pair<long long int,long long int> > kl;
    kl.insert({0,source-1});
    pair<long long int,long long int> tmp;

    while(!kl.empty())
    {
        tmp=(*kl.begin());
        kl.erase(kl.begin());

        int vtx1=tmp.second;
        for(i=0; i<adj[vtx1].size(); i++)
        {
            long long int vtx2=adj[vtx1][i].first;
            long long int wt=adj[vtx1][i].second;
            if(t_int[vtx2]==0)
            {
                if(dist[vtx2] > dist[vtx1] + wt || dist[vtx2]==-1)
                {
                    if(dist[vtx2]!=-1)
                    {
                        kl.erase(kl.find({dist[vtx2],vtx2}));
                    }
                    dist[vtx2] = dist[vtx1] + wt;
                    kl.insert({dist[vtx2],vtx2});
                }
            }
            else
            {
                long long int nextmul=(dist[vtx1]+wt)/t_int[vtx2];
                if(nextmul==0)
                {
                    if(dist[vtx2] > t_int[vtx2] || dist[vtx2]==-1)
                    {
                        if(dist[vtx2]!=-1)
                        {
                            kl.erase(kl.find({dist[vtx2],vtx2}));
                        }
                        dist[vtx2] = t_int[vtx2];
                        kl.insert({dist[vtx2],vtx2});
                    }
                }
                else
                {
                    if( (dist[vtx1]+wt)%t_int[vtx2] ==0 )
                    {
                        if(dist[vtx2] > dist[vtx1] + wt || dist[vtx2]==-1)
                        {
                            if(dist[vtx2]!=-1)
                            {
                                kl.erase(kl.find({dist[vtx2],vtx2}));
                            }
                            dist[vtx2] = dist[vtx1] + wt;
                            kl.insert({dist[vtx2],vtx2});
                        }
                    }
                    else
                    {
                        if(dist[vtx2] > (t_int[vtx2]*(nextmul+1))||dist[vtx2]==-1)
                        {
                            if(dist[vtx2]!=-1)
                            {
                                kl.erase(kl.find({dist[vtx2],vtx2}));
                            }
                            dist[vtx2] = t_int[vtx2]*(nextmul+1);
                            kl.insert({dist[vtx2],vtx2});
                        }
                    }
                }
            }
        }
    }
    cout<<dist[destination-1];
    return 0;
}
