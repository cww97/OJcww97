program cx;
type node=record
       x,y,w:longint; end;
var i,n,m,h1,h2:longint;
    a:array[0..100000]of node;
    home:array[0..100000]of longint;
    check:boolean;

function find(x:longint):longint;
begin
  if home[x]=x then exit(x);
  find:=find(home[x]);
  home[x]:=find;
end;

procedure sort(l,r: longint);
var i,j,x: longint;
    y:node;
begin
  i:=l;
  j:=r;
  x:=a[(l+r) div 2].w;
  repeat
    while a[i].w<x do inc(i);
    while x<a[j].w do dec(j);
    if not(i>j) then
      begin
        y:=a[i];
        a[i]:=a[j];
        a[j]:=y;
        inc(i);
        j:=j-1;
      end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

begin
  read(n,m);
  check:=false;
  for i:=1 to 2*n do home[i]:=i;
  for i:=1 to m do read(a[i].x,a[i].y,a[i].w);
  sort(1,m);

  for i:=m downto 1 do
    begin
      h1:=find(a[i].x);
      h2:=find(a[i].y);
      if h1=h2 then begin check:=true; break;end;
      home[h1]:=find(a[i].y+n);
      home[h2]:=find(a[i].x+n);
    end;

  if not check then writeln(0)
  else
    writeln(a[i].w);
end.