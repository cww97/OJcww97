program cx;  //λͼ位图
uses math;
var i,n,m,top,j:longint;
    st:string;
    ax,ay:array[0..100000]of longint;
    g:array[0..200,0..200]of longint;

function hk(x,y:longint):longint;
var i,ans:longint;
begin
  if g[x,y]=1 then exit(0);
  ans:=maxlongint;
  for i:=1 to top do
    ans:=min(ans,abs(x-ax[i])+abs(y-ay[i]));
  exit(ans);
end;

begin
  readln(n,m);
  for i:=1 to n do
    begin
      readln(st);
      for j:=1 to m do
        if st[j]='0' then g[i,j]:=0
          else begin
                 g[i,j]:=1;
                 inc(top);
                 ax[top]:=i;
                 ay[top]:=j;
               end;
    end;
  for i:=1 to n do
    begin
      for j:=1 to m do write(hk(i,j),' ');
      writeln;
    end;
end.
