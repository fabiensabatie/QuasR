import React from 'react';
import { ToastContainer, toast } from 'react-toastify';
import io from 'socket.io';
import 'react-toastify/dist/ReactToastify.css';
import './App.css';
import axios from 'axios';

const HOST_URL = 'http://localhost:8080';

var Jack = {
	loaders : {},
	init: function() {
		Jack.socket = io(HOST_URL);
		Jack.socket.on('connect', function(){
			Jack.socket.on('jackUpdate', (data) => {
				Jack.loaders[data.id].update(data);
			});
		});
	},
	loader : class Loader {
		constructor(id, querySelector, mode) {
			this.id = id;
			this.querySelector = querySelector;
			this.mode = mode;
			this.div = document.createElement('div');
			this.div.classList.add('blue');
			document.querySelector(querySelector).appendChild(this.div);
			Jack.loaders[id] = this;
		}

		update(data) {
			console.log(data);
			this.div.style.width = data.ratio + '%';
		}
	}

}

Jack.init();
let loader = new Jack.loader('myDiv', '#myLoader');


class MenuItem extends React.Component {
	render() {
		if (this.props.type === 'logo') return <div className="container"><a href={this.props.link} className="item logo"><span role="img" aria-label="Logo">🍑</span></a></div>
		else return <div className="container"><a href={this.props.link} className="item">{this.props.name}</a></div>
	}
}

class Menu extends React.Component {
	render() {
		return <div className="menu">
			<MenuItem link="/" type="logo"></MenuItem>
			<MenuItem name="Home" link="/"></MenuItem>
			<MenuItem name="CodeParser" link="/"></MenuItem>
			<MenuItem name="User" link="/"></MenuItem>
			<MenuItem name="Repos" link="/"></MenuItem>
		</div>;
	}
}

class WorkspaceTitle extends React.Component {
	render () {
		return <h1>{this.props.children}</h1>
	};
}


class RepoInfo extends React.Component {
	constructor(props) {
		super(props);
		this.state         = {service: '', author: '', repo:''};
		this.sendRepoInfo  = this.sendRepoInfo.bind(this);
		this.onValueChange = this.onValueChange.bind(this);
	}

	onValueChange (event) {
		if (!event.target.name) console.error('Your element must have a name.');
		let obj                = {};
		obj[event.target.name] = event.target.value;
		this.setState(obj);
	}

	sendRepoInfo() {
		if (!this.state.service || !this.state.author || !this.state.repo)
			toast.error("Please fill in all the fields!");
		else {
			axios.post(`${HOST_URL}/programs/get_program`, this.state)
			.then((res) => {
				toast.success('Your service file was generated!');
				this.setState({message: res.data});
			})
			.catch((err) => {
				toast.error('An error occured! Check the logs.');
				this.setState({message: JSON.stringify(err)});
			})
		}
	}

	render() {
		return <div>
			<label style={{display: "block"}}>Service    : <input type="text" name="service" value={this.state.service} onChange={this.onValueChange}/></label>
			<label style={{display: "block"}}>Author     : <input type="text" name="author"  value={this.state.author}  onChange={this.onValueChange}/></label>
			<label style={{display: "block"}}>Repository : <input type="text" name="repo"    value={this.state.repo}    onChange={this.onValueChange}/></label>
			<button onClick={this.sendRepoInfo}>Notify !</button>
			<div>{this.state.message}</div>
		</div>
	}
}

class Workspace extends React.Component {
	render () {
		return <div className="workspace">
			<WorkspaceTitle>Your repository information :</WorkspaceTitle>
			<RepoInfo></RepoInfo>
		</div>
	}
}

function App() {
	return (
		<div className="App">
			<Menu name="Fabien"></Menu>
			<Workspace></Workspace>
				<ToastContainer />
		</div>
	);
}

export default App;
