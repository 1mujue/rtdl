# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rtdl_demo_interfaces:msg/ObjectState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ObjectState(type):
    """Metaclass of message 'ObjectState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rtdl_demo_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rtdl_demo_interfaces.msg.ObjectState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__object_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__object_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__object_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__object_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__object_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ObjectState(metaclass=Metaclass_ObjectState):
    """Message class 'ObjectState'."""

    __slots__ = [
        '_name',
        '_room',
        '_support',
        '_held_by_robot',
    ]

    _fields_and_field_types = {
        'name': 'string',
        'room': 'string',
        'support': 'string',
        'held_by_robot': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())
        self.room = kwargs.get('room', str())
        self.support = kwargs.get('support', str())
        self.held_by_robot = kwargs.get('held_by_robot', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.name != other.name:
            return False
        if self.room != other.room:
            return False
        if self.support != other.support:
            return False
        if self.held_by_robot != other.held_by_robot:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @builtins.property
    def room(self):
        """Message field 'room'."""
        return self._room

    @room.setter
    def room(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'room' field must be of type 'str'"
        self._room = value

    @builtins.property
    def support(self):
        """Message field 'support'."""
        return self._support

    @support.setter
    def support(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'support' field must be of type 'str'"
        self._support = value

    @builtins.property
    def held_by_robot(self):
        """Message field 'held_by_robot'."""
        return self._held_by_robot

    @held_by_robot.setter
    def held_by_robot(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'held_by_robot' field must be of type 'bool'"
        self._held_by_robot = value
