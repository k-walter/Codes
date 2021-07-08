# Request for /babelfish
curl 'https://open.kattis.com/problems/babelfish/submit' -H 'User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:88.0) Gecko/20100101 Firefox/88.0' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8' -H 'Accept-Language: en-GB,en;q=0.5' --compressed -H 'Content-Type: multipart/form-data; boundary=---------------------------384425073326051160144160613029' -H 'Origin: https://open.kattis.com' -H 'Alt-Used: open.kattis.com' -H 'Connection: keep-alive' -H 'Referer: https://open.kattis.com/problems/babelfish/submit' -H 'Cookie: site24x7rumID=4430228120391779.1622628783931.1622628783931; EduSiteCookie=513e05b3-dc08-46cc-a39f-5c03d4bd0a06' -H 'Upgrade-Insecure-Requests: 1' -H 'TE: Trailers' --data-binary $'-----------------------------384425073326051160144160613029\r\nContent-Disposition: form-data; name="csrf_token"\r\n\r\n4253803818749990151825955000344489971676\r\n-----------------------------384425073326051160144160613029\r\nContent-Disposition: form-data; name="type"\r\n\r\neditor\r\n-----------------------------384425073326051160144160613029\r\nContent-Disposition: form-data; name="sub_file[]"; filename=""\r\nContent-Type: application/octet-stream\r\n\r\n-----------------------------384425073326051160144160613029\r\nContent-Disposition: form-data; name="sub_code"\r\n\r\nfrom sys import stdin\r\n\r\nd = dict()\r\ndef add(line):\r\n\x09e, f = line.split()\r\n\x09d[f] = e\r\n\r\ndef solve(line):\r\n\x09print(d.get(line, "eh"))\r\n\r\nadding = True\r\nfor line in stdin:\r\n\x09line = line.strip()\r\n\x09if line == "":\r\n\x09\x09adding = False\r\n\x09elif adding:\r\n\x09\x09add(line)\r\n\x09else:\r\n\x09\x09solve(line)\r\n-----------------------------384425073326051160144160613029\r\nContent-Disposition: form-data; name="problem"\r\n\r\nbabelfish\r\n-----------------------------384425073326051160144160613029\r\nContent-Disposition: form-data; name="language"\r\n\r\nPython 3\r\n-----------------------------384425073326051160144160613029\r\nContent-Disposition: form-data; name="submit"\r\n\r\nSubmit\r\n-----------------------------384425073326051160144160613029\r\nContent-Disposition: form-data; name="submit_ctr"\r\n\r\n7\r\n-----------------------------384425073326051160144160613029--\r\n'

# Response Header
# HTTP/3 302 Found
# date: Wed, 02 Jun 2021 10:13:17 GMT
# content-type: text/html; charset=UTF-8
# expires: Thu, 19 Nov 1981 08:52:00 GMT
# cache-control: no-store, no-cache, must-revalidate
# pragma: no-cache
# location: https://open.kattis.com/submissions/7330180      <--- Of particular note
# cf-cache-status: DYNAMIC
# cf-request-id: 0a6dcfa25f000001b0429b6000000001
# expect-ct: max-age=604800, report-uri="https://report-uri.cloudflare.com/cdn-cgi/beacon/expect-ct"
# report-to: {"endpoints":[{"url":"https:\/\/a.nel.cloudflare.com\/report\/v2?s=gzR5abJw3kEe1Mst%2FpiKI0TFknAiBqxPTfz91iWdQycHX5aw0MjpOeCbauLODw%2Frm4kyP%2Bjr2pyPodBR%2FS8QmCjBu0XfLxk3pL1fxepdGMzS9bpz%2F6rCx2iG7ERmSclYn0iJOb3wBE8%3D"}],"group":"cf-nel","max_age":604800}
# nel: {"report_to":"cf-nel","max_age":604800}
# server: cloudflare
# cf-ray: 658fe87d69ed01b0-SIN
# alt-svc: h3-27=":443"; ma=86400, h3-28=":443"; ma=86400, h3-29=":443"; ma=86400, h3=":443"; ma=86400