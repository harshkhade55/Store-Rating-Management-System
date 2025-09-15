import React, {useState, useEffect} from 'react';
import axios from 'axios';

const API = process.env.REACT_APP_API || 'http://localhost:4000/api';

function App(){
  const [token, setToken] = useState(localStorage.getItem('token'));
  const [stores, setStores] = useState([]);
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [name, setName] = useState('');
  const [address, setAddress] = useState('');

  useEffect(()=>{ if(token) fetchStores(); }, [token]);

  const login = async () => {
    try {
      const res = await axios.post(API + '/auth/login', { email, password });
      localStorage.setItem('token', res.data.token);
      setToken(res.data.token);
      alert('Logged in as ' + res.data.user.role);
    } catch (e) { alert(e.response?.data?.message || e.message); }
  };

  const signup = async () => {
    try {
      await axios.post(API + '/auth/signup', { name, email, address, password });
      alert('Signup success, please login');
    } catch (e) { alert(e.response?.data?.message || e.message); }
  };

  const fetchStores = async () => {
    const res = await axios.get(API + '/stores', { headers: { Authorization: 'Bearer '+token }});
    setStores(res.data);
  };

  const submitRating = async (storeId, value) => {
    await axios.post(`${API}/stores/${storeId}/rate`, { value }, { headers:{ Authorization: 'Bearer '+token }});
    fetchStores();
  };

  if (!token) return (
    <div className="container mt-5">
      <h3>Login</h3>
      <input className="form-control my-2" placeholder="Email" value={email} onChange={e=>setEmail(e.target.value)} />
      <input type="password" className="form-control my-2" placeholder="Password" value={password} onChange={e=>setPassword(e.target.value)} />
      <button className="btn btn-primary" onClick={login}>Login</button>

      <hr/>
      <h3>Signup (Normal User)</h3>
      <input className="form-control my-2" placeholder="Name (20-60 chars)" value={name} onChange={e=>setName(e.target.value)} />
      <input className="form-control my-2" placeholder="Email" value={email} onChange={e=>setEmail(e.target.value)} />
      <input className="form-control my-2" placeholder="Address" value={address} onChange={e=>setAddress(e.target.value)} />
      <input type="password" className="form-control my-2" placeholder="Password" value={password} onChange={e=>setPassword(e.target.value)} />
      <button className="btn btn-success" onClick={signup}>Signup</button>
    </div>
  );

  return (
    <div className="container mt-4">
      <div className="d-flex justify-content-between">
        <h3>Stores</h3>
        <button className="btn btn-danger" onClick={()=>{ localStorage.removeItem('token'); setToken(null); }}>Logout</button>
      </div>
      <table className="table mt-3">
        <thead><tr><th>Name</th><th>Address</th><th>Overall Rating</th><th>Your Rating</th><th>Action</th></tr></thead>
        <tbody>
          {stores.map(s=>(
            <tr key={s.id}>
              <td>{s.name}</td>
              <td>{s.address}</td>
              <td>{s.overallRating ?? 'N/A'}</td>
              <td>{s.myRating ?? 'N/A'}</td>
              <td>
                <select defaultValue={s.myRating || ''} onChange={(e)=>submitRating(s.id, e.target.value)}>
                  <option value="">Rate</option>
                  <option value="1">1</option>
                  <option value="2">2</option>
                  <option value="3">3</option>
                  <option value="4">4</option>
                  <option value="5">5</option>
                </select>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default App;
