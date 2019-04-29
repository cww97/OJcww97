program cx;
var i,len,top,j,ans:longint;
    hw:array[0..2222,0..2222]of boolean;
    le,ri,hk:array[0..1000000]of longint;
    st:string;

{function find(l,r,k:longint):longint;
var mid,i:longint;
begin
  if hk[k]<>0 then exit(hk[k]);
  if l=r then exit(l);
  mid:=(l+r) >> 1;
  if le[mid]>k then exit(find(l,mid,k));
  if le[mid]<k then exit(find(mid+1,r,k));
  for i:=mid to top do
    if le[i]<>k then exit(i-1);
end;}

function find(k:longint):longint;
var i:longint;
begin
  for i:=top downto 1 do
    if le[i]<=k then exit(i);
end;

begin
  readln(st);
  len:=length(st);
  fillchar(hw,sizeof(hw),1);
  for i:=2 to len do
    for j:=1 to len-i+1 do
      if (st[j]<>st[j+i-1]) or
         (not hw[j+1,j+i-2]) then hw[j,j+i-1]:=false;

  for i:=1 to len do
    for j:=i to len do
      if hw[i,j] then
        begin
          inc(top);
          le[top]:=i;
          ri[top]:=j;
        end;

  le[top+1]:=maxlongint;

  for i:=1 to top-1 do
    inc(ans,top-find(ri[i]));
  writeln(ans);
end.
