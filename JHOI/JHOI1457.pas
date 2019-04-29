program cx;     //无线通讯网（图论测试第三题） 
var i,n,s,j,hk,top:longint;
    ax,ay,px,py,home:array[0..100000]of longint;
    w,ans:array[0..100000]of double;

procedure sort(l,r: longint);
var i,j,y: longint;
    th,x:double;
begin
  i:=l; j:=r;
  x:=w[(l+r) div 2];
  repeat
    while w[i]<x do inc(i);
    while x<w[j] do dec(j);
    if not(i>j) then
      begin
         th:=w[i]; w[i]:=w[j];   w[j]:=th;
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
  read(s,n);
  for i:=1 to n do home[i]:=i;
  for i:=1 to n do read(px[i],py[i]);
  for i:=1 to n do
    for j:=i+1 to n do
      begin
        inc(top);
        ax[top]:=i;
        ay[top]:=j;
        w[top]:=sqrt(sqr(px[i]-px[j])+sqr(py[i]-py[j]));
      end;

  sort(1,top);
  for i:=1 to n do
    begin
      if home[find(ax[i])]=home[find(ay[i])] then continue;
      inc(hk);
      ans[hk]:=w[i];
      home[find(ax[i])]:=find(ay[i]);
      if hk=n-1 then break;
    end;

  writeln(ans[hk-s]:0:2);
end.
