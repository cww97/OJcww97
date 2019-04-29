program cx;
var i,n:longint;
    st:string;

function danger(st:string):boolean;
var i,j,k,l,len:longint;
begin
  len:=length(st);
  for i:=1 to len-3 do
    for j:=i+1 to len-2 do
      for k:=j+1 to len-1 do
        for l:=k+1 to len do
          begin
            if (st[i]=st[j])and(st[k]=st[l])then exit(true);
            if (st[i]=st[l])and(st[j]=st[k])then exit(true);
          end;
  exit(false);
end;

begin
  assign(input,'fj.in'); reset(input);
  readln(n);
  for i:=1 to n do
    begin
      readln(st);
      if danger(st) then writeln('delete')
        else writeln('safe');
    end;
  close(input);
end.
