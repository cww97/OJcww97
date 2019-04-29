program cx;
var i,n,m,h1,h2:longint;
    ok:boolean;
    ax,ay,aw,home:array[0..1000000]of longint;

function find(x:longint):longint;
begin
  if home[x]=x then exit(x);
  home[x]:=find(home[x]);
  exit(home[x]);
end;

procedure swap(x,y:longint);
begin
  if x=y then exit;
  x:=x xor y;
  y:=x xor y;
  x:=x xor y;
end;

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
        swap(aw[i],aw[j]);
        swap(ax[i],ax[j]);
        swap(ay[i],ay[j]);
        inc(i); j:=j-1;
      end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

begin
  read(n,m);
  for i:=1 to m do read(ax[i],ay[i],aw[i]);
  sort(1,m);
  for i:=1 to n<<1 do home[i]:=i;
  ok:=false;
  for i:=m downto 1 do
    begin
      h1:=find(ax[i]);
      h2:=find(ay[i]);
      if h1=h2 then begin ok:=true; break end;
      home[h1]:=find(ay[i]+n);
      home[h2]:=find(ax[i]+n);
    end;
  if ok then writeln(aw[i])
    else writeln(0);
end.
