program cx;     //วเอÜนýบำ
var i:longint;
    n,m,len,min,l,r,mid,ans,dis,pre,count:int64;
    d:array[0..2000013]of int64;

procedure sort(l,r: int64);
var i,j,x,y: int64;
begin
  i:=l;
  j:=r;
  x:=d[(l+r) shr 1];
  repeat
    while d[i]<x do inc(i);
    while x<d[j] do dec(j);
    if not(i>j) then
      begin
        y:=d[i];
        d[i]:=d[j];
        d[j]:=y;
        inc(i);
        j:=j-1;
      end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

function check(min:int64):boolean;
var i,de,t:int64;
begin
  i:=1;
  t:=0;
  repeat
    de:=d[i]-d[i-1];
    if de>=min then inc(i)
    else
      repeat
        inc(t);
        inc(i);
        de:=de+d[i]-d[i-1];
      until de>=min;
    if t>m then exit(false);
  until i=n+1;
  exit(true);
end;

begin
  read(len,n,m);
  for i:=1 to n do read(d[i]);
  sort(1,n);
  min:=maxlongint;
  d[n+1]:=len;
  for i:=1 to n+1 do
    if d[i]-d[i-1]<min then min:=d[i]-d[i-1];

  l:=min;
  r:=len;
  while l<=r do
    begin
      mid:=(l+r)shr 1;
      //if check(mid) then l:=mid+1
      //else r:=mid-1;
      pre:=0;count:=0;
      for i:=1 to n do
        begin
          dis:=d[i]-d[pre];
          if(dis<mid)then inc(count)
          else pre:=i;
        end;
      if(count > m) then r:=mid-1
      else l:=mid + 1;
    end;
  writeln(r);
end.