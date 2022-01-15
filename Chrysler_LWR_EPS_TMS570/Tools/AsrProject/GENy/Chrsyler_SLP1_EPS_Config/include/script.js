////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2003,2004 Cezary Tomczak                                             //
// All rights reserved.                                                               //
//                                                                                    //
// Redistribution and use in source and binary forms, with or without modification,   //
// are permitted provided that the following conditions are met:                      //
//                                                                                    //
//     - Redistributions of source code must retain the above copyright notice,       //
//       this list of conditions and the following disclaimer.                        //
//     - Redistributions in binary form must reproduce the above copyright notice,    //
//       this list of conditions and the following disclaimer in the documentation    //
//       and/or other materials provided with the distribution.                       //
//     - Neither the name of the Cezary Tomczak nor the names of its contributors     //
//       may be used to endorse or promote products derived from this software        //
//       without specific prior written permission.                                   //
//                                                                                    //
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"        //
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,              //
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE     //
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE    //
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL         //
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR         //
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER         //
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,      //
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE      //
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.               //
//                                                                                    //
// --------------------------------------------------------------------------------   //
//                                                                                    //
// For more information on the mygosuMenu project,                                    //
// please see http://gosu.pl/dhtml/mygosumenu.html                                    //
////////////////////////////////////////////////////////////////////////////////////////

// +---------------------------------------------------------------+
// | DO NOT REMOVE THIS                                            |
// +---------------------------------------------------------------+
// | DynamicTree 1.5.2                                             |
// | Author: Cezary Tomczak [www.gosu.pl]                          |
// | Free for any use as long as all copyright messages are intact |
// +---------------------------------------------------------------+

function DynamicTree(id) 
{
	this.foldersAsLinks = false;
	this.path = "images/";
	this.img = {
		"branch": "tree-branch.gif",
		"doc": "tree-doc.gif",
		"folder": "tree-folder.gif",
		"folderOpen": "tree-folder-open.gif",
		"leaf": "tree-leaf.gif",
		"leafEnd": "tree-leaf-end.gif",
		"node": "tree-node.gif",
		"nodeEnd": "tree-node-end.gif",
		"nodeOpen": "tree-node-open.gif",
		"nodeOpenEnd": "tree-node-open-end.gif" };
	this.cookiePath = "";
	this.cookieDomain = "";
	
	var self = this;
	this.id = id;
	this.tree = new Node("tree", "", null, new Array(), false, true);
	this.allNodes = {}; // id => object
	this.opened = []; // opened folders
	this.active = ""; // active node, text clicked
	this.cookie = new Cookie();
	this.imgObjects = [];
	this.count = 0;
	
	this.init = function() 
	{
		var p, img;
		for (p in this.img) 
		{
			this.img[p] = this.path + this.img[p];
		}
		for (p in this.img) 
		{
			this.imgObjects.push(new Image());
			this.imgObjects.getLast().src = this.img[p];
			this.img[p] = this.imgObjects.getLast().src;
		}
		this.parse(document.getElementById(this.id).childNodes, this.tree, 1);
		this.loadState();
		if (window.addEventListener) 
		{ 
			window.addEventListener("unload", function(e) { self.saveState(); }, false); 
		}
		else if (window.attachEvent) 
		{ 
			window.attachEvent("onunload", function(e) { self.saveState(); }); 
		}
		this.updateHtml();
	};
	
	this.parse = function(nodes, tree) 
	{
		for (var i = 0; i < nodes.length; i++) 
		{
			if (nodes[i].nodeType == 1) 
			{
				if (!nodes[i].className) 
				{ 
					continue; 
				}
				if (!nodes[i].id) 
				{
					nodes[i].id = this.id + "-" + (++this.count);
				}
				var node = new Node();
				node.id = nodes[i].id;
				if (nodes[i].firstChild) 
				{
					if (nodes[i].firstChild.tagName == "A") 
					{
						var a = nodes[i].firstChild;
						if (a.firstChild) 
						{
							node.text = a.firstChild.nodeValue.trim();
						}
						if (a.href) 
						{
							node.href = a.href;
						}
						if (a.title) 
						{
							node.title = a.title;
						}
                        if (a.target) 
                        {
                            node.target = a.target;
                        }
					} 
					else 
					{
						node.text = nodes[i].firstChild.nodeValue.trim();
					}
				}
				node.parentNode = tree;
				node.childNodes = (nodes[i].className == "folder" ? new Array() : null);
				node.isDoc      = (nodes[i].className == "doc");
				node.isFolder   = (nodes[i].className == "folder");
				tree.childNodes.push(node);
				this.allNodes[node.id] = node;
			}
			if (nodes[i].nodeType == 1 && nodes[i].childNodes) 
			{
				this.parse(nodes[i].childNodes, tree.childNodes.getLast());
			}
		}
	};
	
	this.nodeClick = function(id) 
	{
		var el   = document.getElementById(id + "-section");
		var node = document.getElementById(id + "-node");
		var icon = document.getElementById(id + "-icon");
		if (el.style.display == "block") 
		{
			el.style.display = "none";
			if (this.allNodes[id].isLast()) 
			{ 
				node.src = this.img.nodeEnd; 
			}
			else 
			{ 
				node.src = this.img.node; 
			}
			icon.src = this.img.folder;
			this.opened.removeByValue(id);
		} 
		else 
		{
			el.style.display = "block";
			if (this.allNodes[id].isLast()) 
			{ 
				node.src = this.img.nodeOpenEnd; 
			}
			else 
			{ 
				node.src = this.img.nodeOpen; 
			}
			icon.src = this.img.folderOpen;
			this.opened.push(id);
		}
		/* fix ie bug - images not showing */
		if (node.outerHTML) 
		{ 
			node.outerHTML = node.outerHTML; 
		}
		if (icon.outerHTML) 
		{ 
			icon.outerHTML = icon.outerHTML; 
		}
	};
	
	this.toHtml = function() 
	{
		var s = "";
		var nodes = this.tree.childNodes;
		for (var i = 0; i < nodes.length; i++) 
		{
			s += nodes[i].toHtml();
		}
		return s;
	};
	
	this.updateHtml = function() 
	{
		document.getElementById(this.id).innerHTML = this.toHtml();
	};
	
	this.loadState = function() 
	{
		var opened = this.cookie.get("opened");
		if (opened) 
		{
			this.opened = opened.split("|");
			this.opened.filter(function(id) { return self.allNodes[id] && self.allNodes[id].isFolder && self.allNodes[id].childNodes.length;  });
		}
	};
	this.saveState = function() 
	{
		if (this.opened.length) 
		{
			this.cookie.set("opened", this.opened.join("|"), 3600*24*30, this.cookiePath, this.cookieDomain);
		} 
		else 
		{
			this.clearState();
		}
	};
	
	this.clearState = function() 
	{
		this.cookie.del("opened");
	};
	
	function Node(id, text, parentNode, childNodes, isDoc, isFolder) 
	{
		this.id = id;
		this.text = text;
		this.parentNode = parentNode;
		this.childNodes = childNodes;
		this.isDoc = isDoc;
		this.isFolder = isFolder;
		this.href = "";
		this.title = "";
		this.target = "";
		
		this.isLast = function() 
		{
			if (this.parentNode) 
			{
				return this.parentNode.childNodes.getLast().id == this.id;
			}
			throw "DynamicTree.Node.isLast() failed, this func cannot be called for the root element";
		};
		
		this.toHtml = function() 
		{
			var s = '<div class="?" id="?">'.format((this.isFolder ? "folder" : "doc"), this.id);
			if (this.isFolder) 
			{
				var nodeIcon;
				if (this.childNodes.length) 
				{
					nodeIcon = (self.opened.contains(this.id) ? (this.isLast() ? self.img.nodeOpenEnd : self.img.nodeOpen) : (this.isLast() ? self.img.nodeEnd : self.img.node));
				} 
				else 
				{
					nodeIcon = (this.isLast() ? self.img.leafEnd : self.img.leaf);
				}
				var icon = ((self.opened.contains(this.id) && this.childNodes.length) ? self.img.folderOpen : self.img.folder);
				if (this.childNodes.length) 
				{ 
					s += '<a href="javascript:void(0)" onclick="?.nodeClick(\'?\')">'.format(self.id, this.id); 
				}
				s += '<img id="?-node" src="?" width="18" height="18" alt="" />'.format(this.id, nodeIcon);
				if (this.childNodes.length) 
				{ 
					s += '</a>';
				}
				s += '<img id="?-icon" src="?" width="18" height="18" alt="" />'.format(this.id, icon);
				if (self.foldersAsLinks) 
				{
                    s += '<a href="?"??>?</a>'.format(this.href, (this.title ? ' title="?"'.format(this.title) : ""), (this.target ? ' target="?"'.format(this.target) : ""), this.text);
				} 
				else 
				{
					s += this.text;
				}
				if (this.childNodes.length) 
				{
					s += '<div class="section?" id="?-section"'.format((this.isLast() ? " last" : ""), this.id);
					if (self.opened.contains(this.id)) 
					{
						s += '  style="display: block;"'; 
					}
					s += '>';
					for (var i = 0; i < this.childNodes.length; i++) 
					{
						s += this.childNodes[i].toHtml();
					}
					s += '</div>';
				}
			}
			if (this.isDoc) 
			{
				s += '<img src="?" width="18" height="18" alt="" /><img src="?" width="18" height="18" alt="" />'.format((this.isLast() ? self.img.leafEnd : self.img.leaf), self.img.doc);
                s += '<a href="?"??>?</a>'.format(this.href, (this.title ? ' title="?"'.format(this.title) : ""), (this.target ? ' target="?"'.format(this.target) : ""), this.text);
			}
			s += '</div>';
			return s;
		};
	}
	
	function Cookie() 
	{
		this.get = function(name) 
		{
			var cookies = document.cookie.split(";");
			for (var i = 0; i < cookies.length; ++i) 
			{
				var a = cookies[i].split("=");
				if (a.length == 2) 
				{
					a[0] = a[0].trim();
					a[1] = a[1].trim();
					if (a[0] == name) 
					{
						return unescape(a[1]);
					}
				}
			}
			return "";
		};
		
		this.set = function(name, value, seconds, path, domain, secure) 
		{
			var cookie = (name + "=" + escape(value));
			if (seconds) 
			{
				var date = new Date(new Date().getTime()+seconds*1000);
				cookie += ("; expires="+date.toGMTString());
			}
			cookie += (path    ? "; path="+path : "");
			cookie += (domain  ? "; domain="+domain : "");
			cookie += (secure  ? "; secure" : "");
			document.cookie = cookie;
		};
		
		this.del = function(name) 
		{
			document.cookie = name + "=; expires=Thu, 01-Jan-70 00:00:01 GMT";
		};
	}
	
}

/* Check whether array contains given string */
if (!Array.prototype.contains) {
	Array.prototype.contains = function(s) {
		for (var i = 0; i < this.length; ++i) {
			if (this[i] === s) { return true; }
		}
		return false;
	};
}

/* Remove elements with such value (mutates) */
if (!Array.prototype.removeByValue) {
	Array.prototype.removeByValue = function(value) {
		var i, indexes = [];
		for (i = 0; i < this.length; ++i) {
			if (this[i] === value) { indexes.push(i); }
		}
		for (i = indexes.length - 1; i >= 0; --i) {
			this.splice(indexes[i], 1);
		}
	};
}

/* Remove elements judged 'false' by the passed function (mutates) */
if (!Array.prototype.filter) {
	Array.prototype.filter = function(func) {
		var i, indexes = [];
		for (i = 0; i < this.length; ++i) {
			if (!func(this[i])) { indexes.push(i); }
		}
		for (i = indexes.length - 1; i >= 0; --i) {
			this.splice(indexes[i], 1);
		}
	};
}

/* Get the last element from the array */
if (!Array.prototype.getLast) {
	Array.prototype.getLast = function() {
		return this[this.length-1];
	};
}

/* Strip whitespace from the beginning and end of a string */
if (!String.prototype.trim) {
	String.prototype.trim = function() {
		return this.replace(/^\s*|\s*$/g, "");
	};
}

/* Replace ? tokens with variables passed as arguments in a string */
String.prototype.format = function() {
	if (!arguments.length) { throw "String.format() failed, no arguments passed, this = "+this; }
	var tokens = this.split("?");
	if (arguments.length != (tokens.length - 1)) { throw "String.format() failed, tokens != arguments, this = "+this; }
	var s = tokens[0];
	for (var i = 0; i < arguments.length; ++i) {
		s += (arguments[i] + tokens[i + 1]);
	}
	return s;
};


// +----------------------------------------------------------------+
// | Array functions that are missing in IE 5.0                     |
// | Author: Cezary Tomczak [www.gosu.pl]                           |
// | Free for any use as long as all copyright messages are intact. |
// +----------------------------------------------------------------+

// Removes the last element from an array and returns that element.
if (!Array.prototype.pop) 
{
	Array.prototype.pop = function() 
	{
		var last;
		if (this.length) 
		{
			last = this[this.length - 1];
			this.length -= 1;
		}
		return last;
	};
}

// Adds one or more elements to the end of an array and returns the new length of the array.
if (!Array.prototype.push) 
{
	Array.prototype.push = function() 
	{
		for (var i = 0; i < arguments.length; ++i) 
		{
			this[this.length] = arguments[i];
		}
		return this.length;
	};
}

// Removes the first element from an array and returns that element.
if (!Array.prototype.shift) 
{
	Array.prototype.shift = function() 
	{
		var first;
		if (this.length) 
		{
			first = this[0];
			for (var i = 0; i < this.length - 1; ++i) 
			{
				this[i] = this[i + 1];
			}
			this.length -= 1;
		}
		return first;
	};
}

// Adds one or more elements to the front of an array and returns the new length of the array.
if (!Array.prototype.unshift) 
{
	Array.prototype.unshift = function() 
	{
		if (arguments.length) 
		{
			var i, len = arguments.length;
			for (i = this.length + len - 1; i >= len; --i) 
			{
				this[i] = this[i - len];
			}
			for (i = 0; i < len; ++i) 
			{
				this[i] = arguments[i];
			}
		}
		return this.length;
	};
}

// Adds and/or removes elements from an array.
if (!Array.prototype.splice) 
{
	Array.prototype.splice = function(index, howMany) 
	{
		var elements = [], removed = [], i;
		for (i = 2; i < arguments.length; ++i) 
		{
			elements.push(arguments[i]);
		}
		for (i = index; (i < index + howMany) && (i < this.length); ++i) 
		{
			removed.push(this[i]);
		}
		for (i = index + howMany; i < this.length; ++i) 
		{
			this[i - howMany] = this[i];
		}
		this.length -= removed.length;
		for (i = this.length + elements.length - 1; i >= index + elements.length; --i) 
		{
			this[i] = this[i - elements.length];
		}
		for (i = 0; i < elements.length; ++i) 
		{
			this[index + i] = elements[i];
		}
		return removed;
	};
}