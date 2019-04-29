program cx;
const qq:array[1..9,1..9]of longint=((1,1,1,2,2,2,3,3,3),
                                     (1,1,1,2,2,2,3,3,3),
                                     (1,1,1,2,2,2,3,3,3),
                                     (4,4,4,5,5,5,6,6,6),
                                     (4,4,4,5,5,5,6,6,6),
                                     (4,4,4,5,5,5,6,6,6),
                                     (7,7,7,8,8,8,9,9,9),
                                     (7,7,7,8,8,8,9,9,9),
                                     (7,7,7,8,8,8,9,9,9));
      po:array[1..9,1..9]of longint=((6,6,6,6,6,6,6,6,6),
                                     (6,7,7,7, 7,7,7,7,6),
                                     (6,7,8,8, 8,8,8,7,6),
                                     (6,7,8,9, 9,9,8,7,6),
                                     (6,7,8,9,10,9,8,7,6),
                                     (6,7,8,9, 9,9,8,7,6),
                                     (6,7,8,8, 8,8,8,7,6),
                                     (6,7,7,7, 7,7,7,7,6),
                                     (6,6,6,6, 6,6,6,6,6));
var i,j,n,top,time,max:longint;
    g:array[0..10,0..10]of longint;
    ha,li,qu:array[0..10,0..10]of boolean;
    ax,ay:array[0..100]of longint;
    ok:boolean;
    st:string;

procedure dfs(k:longint);
var i,j,ans:longint;
begin
  if k=top+1 then
    begin  
      ans:=0;
      for i:=1 to 9 do
        for j:=1 to 9 do inc(ans,po[i,j]*g[i,j]);
      if ans>max then max:=ans;
      exit;
    end;
  for i:=1 to 9 do
    begin
      if ha[ax[k],i] then continue;
      if li[ay[k],i] then continue;
      if qu[qq[ax[k],ay[k]],i] then continue;
      g[ax[k],ay[k]]:=i;
      ha[ax[k],i]:=true;
      li[ay[k],i]:=true;
      qu[qq[ax[k],ay[k]],i]:=true;
      dfs(k+1);
      ha[ax[k],i]:=false;
      li[ay[k],i]:=false;
      qu[qq[ax[k],ay[k]],i]:=false;
    end;
end;

begin

      ok:=false;
      top:=0;
      fillchar(g,sizeof(g),0);
      fillchar(ha,sizeof(ha),0);
      fillchar(li,sizeof(li),0);
      fillchar(qu,sizeof(qu),0);
      for i:=1 to 9 do
        for j:=1 to 9 do
          begin
            read(g[i,j]);
            if g[i,j]=0 then
              begin inc(top); ax[top]:=i; ay[top]:=j; end
              else
                begin
                  ha[i,g[i,j]]:=true;
                  li[j,g[i,j]]:=true;
                  qu[qq[i,j],g[i,j]]:=true;
                end;
          end;
      dfs(1);
      if max>0 then
      writeln(max)
      else writeln(-1)
end.
