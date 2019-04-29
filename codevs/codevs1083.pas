program cx;
var i,n:longint;
    s:array[0..10000000]of longint;

begin
  read(n);
  for i:=1 to 10000 do
    begin
      s[i]:=s[i-1]+i;
      if s[i]=n then
        begin
          if odd(i) then writeln(1,'/',i)
            else writeln(i,'/',1);
          break;
        end
      else if s[i]>n then
        begin
          if odd(i) then writeln(i-n+s[i-1]+1,'/',n-s[i-1])
          else writeln(n-s[i-1],'/',i-n+s[i-1]+1);
          break;
        end;
    end;
end.
