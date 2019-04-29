program cx;
uses math;
const dx:array[1..4]of longint=(1,-1,0,0);
      dy:array[1..4]of longint=(0,0,-1,1);
var i,j,n,m,ans,t,xx,yy:longint;
    g:array[0..1000,0..1000]of longint;

function gym(x,y:longint):longint;
var i:longint;
begin
  gym:=0;
  for i:=1 to 4 do
    if g[x,y]*g[x+dx[i],y+dy[i]]<0 then
      inc(gym,abs(g[x+dx[i],y+dy[i]]))
      else dec(gym,abs(g[x+dx[i],y+dy[i]]));
end;

begin
  read(n,m);
  while (m<>0)and(n<>0) do
  begin
    fillchar(g,sizeof(g),0);
    for i:=1 to n do
      for j:=1 to m do read(g[i,j]);
    ans:=-maxlongint;
    for i:=1 to n do
      for j:=1 to n do
        begin
          t:=gym(i,j);
          if t>ans then
            begin
              ans:=t;
              xx:=i; yy:=j;
            end;
        end;
    writeln(xx,' ',yy,' ',ans);
    read(n,m);
  end;
end.
