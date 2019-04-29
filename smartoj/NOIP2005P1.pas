program cx;
var xy,i,ans:longint;
    a:array[0..100]of longint;

begin
  for i:=1 to 10 do
    begin
      read(a[i]);
      a[i]:=a[i]-30;
    end;
  read(xy);
  ans:=0;
  for i:=1 to 10 do
    if xy>=a[i] then inc(ans);
  writeln(ans);
end.
