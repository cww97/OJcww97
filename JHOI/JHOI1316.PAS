program cx;
var i,t,n,x:longint;
    v:array[0..1000000]of boolean;
begin
  fillchar(v,sizeof(v),0);
  read(n);
  for i:=1 to n do
    begin
      read(x);
      if v[x] then inc(t);
      v[x]:=true;
    end;
  writeln(n-t);
  for i:=1 to 1000000 do
    if v[i] then write(i,' ');
  writeln;
end.
