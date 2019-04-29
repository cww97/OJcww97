program cx;
var i,j,k,l:longint;
    n:int64;
    st:string;
    ok:boolean;

begin
  //assign(input,'p1088.in');  reset(input);
  //assign(output,'p1088.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
      readln(st);
      l:=length(st);
      ok:=true;
      for j:=1 to l shr 1 do
        if st[j]<>st[l-j+1] then
          begin
            ok:=false;
            break;
          end;
      if ok then writeln('YES')
      else writeln('NO');
    end;
  //close(input);
  //close(output);
end.
