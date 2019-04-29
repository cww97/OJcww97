program cx;
var i,j,n,cnt,sum,top:longint;
    home,ax,ay,aw:array[0..100000]of longint;
    g:array[0..200,0..200]of longint;

procedure sort(l,r: longint);
var i,j,x,y: longint;
begin
  i:=l; j:=r;
  x:=aw[(l+r)>>1];
  repeat
    while aw[i]<x do inc(i);
    while x<aw[j] do dec(j);
    if not(i>j) then
      begin
         y:=aw[i]; aw[i]:=aw[j]; aw[j]:=y;
         y:=ax[i]; ax[i]:=ax[j]; ax[j]:=y;
         y:=ay[i]; ay[i]:=ay[j]; ay[j]:=y;
         inc(i); j:=j-1;
      end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

function find(x:longint):longint;
begin
  if home[x]=x then exit(x);
  home[x]:=find(home[x]);
  exit(home[x]);
end;

begin
  read(n);
  for i:=1 to n do
    for j:=1 to n do  read(g[i,j]);
  for i:=2 to n do
    for j:=1 to i-1 do
      begin
        inc(cnt);
        ax[cnt]:=i;
        ay[cnt]:=j;
        aw[cnt]:=g[i,j];
      end;
  sort(1,cnt);
  for i:=1 to n do home[i]:=i;
  for i:=1 to cnt do
    begin
      if find(ax[i])=find(ay[i]) then continue;
      home[find(ax[i])]:=find(ay[i]);
      inc(sum,aw[i]);
      inc(top);
      if top=n-1 then break;
    end;
  writeln(sum);
end.
