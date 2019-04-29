program cx;
var i,hk,j,x,y,n,m,ans:longint;
    a,b:array[0..1000000]of longint;
    ok:boolean;

begin
  read(n,m,x,y);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do read(b[i]);
  hk:=1;
  for i:=1 to m do
    begin
      for j:=hk to n do
        begin
          if b[i]<a[j]-x then continue;
          if b[i]>a[j]+y then continue;
          break;
        end;
      if (b[i]<=a[j]+y)and(b[i]>=a[j]-x) then
        begin
          hk:=j+1;
          inc(ans);
        end;
    end;
  writeln(ans);
end.
