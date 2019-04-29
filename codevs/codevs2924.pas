{
作者:CWW970329
题目:p2924 数独挑战
}

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
var i,j,n,top,time:longint;
    g:array[0..10,0..10]of longint;
    ha,li,qu:array[0..10,0..10]of boolean;
    ax,ay:array[0..100]of longint;
    ok:boolean;
    st:string;

procedure dfs(k:longint);
var i:longint;
begin
  if ok then exit;
  if k=top+1 then
    begin ok:=true; exit; end;
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
      if ok then exit;
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
      for i:=1 to 9 do
        begin
        for j:=1 to 8 do write(g[i,j],' ');
        writeln(g[i,9]);
        end;
end.
